"""
Requires stlink v1.6.0
"""

import os
import click
import colorama

MBED_GEN_CMD = '''mbed-tools configure -m {MBED_TARGET} -t GCC_ARM -o cmake_build/{PORT}/ --mbed-os-path ports/mbed_common/mbed-os --app-config ports/{PORT}/mbed/mbed_app.json '''

CMAKE_GEN_CMD = '''cmake -S .  -B cmake_build/{PORT} -G Ninja -DPLATFORM={PORT}'''
CMAKE_BUILD_CMD = '''cmake --build cmake_build/{PORT}'''

DEFAULT_MBED_TARGET = "NUCLEO_G071RB"

def build_image(port, platform, mbed_target = DEFAULT_MBED_TARGET):
    print(port)
    if platform == "MBED":
        print("MBED Platform")
        mbed_gen_command = MBED_GEN_CMD.format(MBED_TARGET = mbed_target, PORT = port)
        ret = os.system(" ".join(mbed_gen_command.split("\n")))
        if ret != 0:
            raise Exception("CMake generation failed!")
    elif platform == "ESP_IDF":
        print("ESP-IDF PLATFORM")
    print(colorama.Fore.CYAN, "Building Image" + colorama.Style.RESET_ALL)
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


def _flash_application():
    print(colorama.Fore.MAGENTA, "Flashing Image" + colorama.Style.RESET_ALL)


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
        _flash_application()


if __name__ == "__main__":
    cli()
