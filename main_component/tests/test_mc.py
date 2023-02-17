import pytest
import subprocess
from os import path


def test_mc():

    Inputfile_content = """ 
set temperature 72.43
"""

    expected_read_content = """\
{
	"cmds " : [ 
		{"ID": 103, "length":10 , "value": " 72.43" }
	]
}
"""

    input_filename = "inputs.txt"
    output_filename = "output.txt"
    print(Inputfile_content)

    with open(input_filename, "w") as fd:
        fd.write(Inputfile_content)

    mc_filename = path.join(path.curdir, "../..",
                            "build", "main_component", "main_component")

    with open(output_filename, "w") as fd:
        pass

    mc_process = subprocess.run(args=[mc_filename,
                                input_filename, output_filename], capture_output=True)
    captured_output = mc_process.stdout.decode()
    print(captured_output)

    read_output = ""

    with open(output_filename) as fd:
        read_output = fd.read()

    print(f'_{read_output}_')
    print(f'_{expected_read_content}_')

    assert read_output == expected_read_content
