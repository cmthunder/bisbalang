const dataCount = 30000;
let data, pointer;

function run()
{
    data = new Array(dataCount).fill(0);
    pointer = 0;
    document.getElementById("outputTextbox").value = "";

    let inputPointer = 0;

    let program = document.getElementById("inputTextbox").value.split(" ");

    if(program.length % 2 != 0)
    {
        document.getElementById("outputTextbox").value = "Error: Wrong count of words (" + program.length.toString() + ").";
        return;
    }

    for(let i = 0; i < program.length; i+=2)
    {
        let wordA = program[i], wordB = program[i+1];

        if(wordA == "camina" && wordB == "y") pointer = (pointer + 1) % dataCount;
        else if(wordA == "y" && wordB == "camina") pointer = (pointer == 0) ? dataCount - 1 : pointer - 1;
        else if(wordA == "camina" && wordB == "camina") data[pointer] = (data[pointer] + 1) % 256;
        else if(wordA == "ven" && wordB == "ven") data[pointer] = (data[pointer] == 0) ? 255 : data[pointer] - 1;
        else if(wordA == "ven" && wordB == "camina") document.getElementById("outputTextbox").value += String.fromCharCode(data[pointer]);
        else if(wordA == "camina" && wordB == "ven") data[pointer] = document.getElementById("programInputTextbox").value[inputPointer++].charCodeAt(0);
        else if(wordA == "ven" && wordB == "y") if(data[pointer] == 0) while(!(program[i] == "y" && program[i+1] == "ven")) i += 2;
        else if(wordA == "y" && wordB == "ven") if(data[pointer] != 0) while(!(program[i] == "ven" && program[i+1] == "y")) i -= 2;
        else
        {
            document.getElementById("outputTextbox").value = "Error: Unknown instruction at word " + i.toString() + ".";
            return;
        }
    }
}