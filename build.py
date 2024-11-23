"""
Requires stlink v1.6.0
"""

import os
import click
import colorama

CMAKE_GEN_CMD = '''cmake -S .  -B cmake_build/{VARIANT} -G Ninja -DPLATFORM={VARIANT}'''
CMAKE_BUILD_CMD = '''cmake --build cmake_build/{VARIANT}'''

DEFAULT_VARIANT="STM32G070X"
def build_image(variant=DEFAULT_VARIANT):
    print(colorama.Fore.CYAN, "Building Image" + colorama.Style.RESET_ALL)
    cmake_gen_command = CMAKE_GEN_CMD.format(VARIANT=variant)
    cmake_build_command = CMAKE_BUILD_CMD.format(VARIANT=variant)
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
@click.option("-v", "-variant", "variant", default=DEFAULT_VARIANT,type=click.STRING, help="optional variant")
@click.option("--compile", is_flag=True, help="compile image, default False")
@click.option("--flash", is_flag=True, help="flash image, default False")
def build_application(variant, compile, flash):
    if compile:
        build_image(variant)
    if flash:
        _flash_application()

if __name__ == "__main__":
    cli()
