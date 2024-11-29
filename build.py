"""
Requires stlink v1.6.0
"""

import os
import click
import colorama
import subprocess

MBED_GEN_CMD = '''mbed-tools configure -m {MBED_TARGET} -t GCC_ARM -o cmake_build/{PORT}/ --mbed-os-path ports/mbed_common/mbed-os --app-config ports/{PORT}/mbed/mbed_app.json '''

ESP_IDF_DIR = '''$HOME/esp/'''

CMAKE_GEN_CMD = '''cmake -S .  -B cmake_build/{PORT} -G Ninja -DPLATFORM={PORT}'''
CMAKE_BUILD_CMD = '''cmake --build cmake_build/{PORT}'''

IMAGE_DIR = '''cmake_build/{PORT}/RB20.bin'''

ST_FLASH_APPLICATION_CMD = '''st-flash write 
{IMAGE} 0x8000000 && st-info --reset
'''

ESP_FLASH_APPLICATION_CMD = '''ninja -C cmake_build/{PORT}/ flash'''

DEFAULT_MBED_TARGET = "NUCLEO_G071RB"

def set_up_idf_env(esp_idf_dir):
    export_cmd = f"source {esp_idf_dir}/esp-idf/export.sh && env"
    try:
        output = subprocess.check_output(export_cmd, shell=True, executable='/bin/bash', text=True)
        for line in output.splitlines():
            if '=' in line:
                key, value = line.split('=', 1)
                os.environ[key] = value
    except subprocess.CalledProcessError as e:
        raise Exception(f"Could not set up ESP-IDF environment: {e}")
def build_image(port, platform, mbed_target = DEFAULT_MBED_TARGET):
    print(colorama.Fore.MAGENTA + "Compiling firmware" + colorama.Style.RESET_ALL)
    print(port)
    if platform == "MBED":
        print("MBED Platform")
        print(colorama.Fore.CYAN, "Generating mbed config files" + colorama.Style.RESET_ALL)
        mbed_gen_command = MBED_GEN_CMD.format(MBED_TARGET = mbed_target, PORT = port)
        ret = os.system(" ".join(mbed_gen_command.split("\n")))
        if ret != 0:
            raise Exception("CMake generation failed!")
    elif platform == "ESP_IDF":
        print("ESP-IDF PLATFORM")
        print(colorama.Fore.CYAN, "Sourcing ESP-IDF environment" + colorama.Style.RESET_ALL)
        set_up_idf_env(ESP_IDF_DIR)
    cmake_gen_command = CMAKE_GEN_CMD.format(PORT=port)
    cmake_build_command = CMAKE_BUILD_CMD.format(PORT=port)
    print(cmake_gen_command)
    ret = os.system(" ".join(cmake_gen_command.split("\n")))
    if ret != 0:
        raise Exception("CMake generation failed!")
    print(cmake_build_command)
    ret = os.system(" ".join(cmake_build_command.split("\n")))
    if ret != 0:
        raise Exception("CMake build failed")

    print(colorama.Fore.GREEN + "Compiled firmware successfully" + colorama.Style.RESET_ALL)


def _flash_application(port, image):
    print(colorama.Fore.MAGENTA, "Flashing Image" + colorama.Style.RESET_ALL)
    global flash_cmd
    if port == "STM32G070X":
        flash_cmd = ST_FLASH_APPLICATION_CMD.format(IMAGE = image)
    elif port == "ESP32":
        flash_cmd = ESP_FLASH_APPLICATION_CMD.format(PORT = port)
    print(flash_cmd)
    ret = os.system(" ".join(flash_cmd.split("\n")))
    if ret != 0:
        raise Exception("Flashing failed")
    else:
        print(colorama.Fore.GREEN, "Flashing Success" + colorama.Style.RESET_ALL)

@click.group()
def cli():
    """
    firmware build tool
    :return:
    """
    print(colorama.Fore.LIGHTGREEN_EX, "[CLI]\n" + colorama.Style.RESET_ALL)


@cli.command()
@click.option("-p", "-port", "port", required=True, type=click.STRING, help="mandatory port")
@click.option("-pl", "-platform", "platform", required=True, type=click.STRING, help="mandatory platform")
@click.option("--compile", is_flag=True, help="compile image, default False")
@click.option("--flash", is_flag=True, help="flash image, default False")
def build_application(port, platform, compile, flash):
    if compile:
        build_image(port, platform)
    if flash:
        image_dir = IMAGE_DIR.format(PORT = port)
        _flash_application(port, image_dir)


if __name__ == "__main__":
    cli()
