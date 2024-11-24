"""
Requires stlink v1.6.0
"""

import os
import click
import colorama

CMAKE_GEN_CMD = '''cmake -S .  -B cmake_build/{PORT} -G Ninja -DPLATFORM={PORT}'''
CMAKE_BUILD_CMD = '''cmake --build cmake_build/{PORT}'''

DEFAULT_PORT="STM32G070X"
def build_image(port=DEFAULT_PORT):
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
@click.option("-p", "-port", "port", default=DEFAULT_PORT,type=click.STRING, help="mandatory port")
@click.option("--compile", is_flag=True, help="compile image, default False")
@click.option("--flash", is_flag=True, help="flash image, default False")
def build_application(port, compile, flash):
    if compile:
        build_image(port)
    if flash:
        _flash_application()

if __name__ == "__main__":
    cli()
