import os
import shutil


fileName = input("What is the name of the file? ")
folderPath = "/Users/Eddie/source/repos/PythonCodingChallenge/PythonCodingChallenge/"
programPath = "/Users/Eddie/source/repos/CodingChallenge/CodingChallenge/"
programName = fileName.split('.')
programName = programName[0]
#Moves files
if os.path.exists("/Users/Eddie/source/repos/CodingChallenge/CodingChallenge/"+fileName):
        #create textfile
    
    arr = []
    arr.append("Description of "+programName+"\n")
    arr.append(input("What is a description of "+programName+"\n")+"\n")
    arr.append("Thoughts on "+programName+"\n")
    arr.append(input("What did you think of "+programName+"\n")+"\n")
    arr.append("What I learned:\n")
    arr.append(input("What did you learn from"+programName+"\n")+"\n")
    arr.append("What I would do if I had more time\n")
    arr.append(input("What would you do if you had more time"+"\n")+"\n")
    ideas = bool(input("Do you have any ideas? (0 or 1)"))
    if(ideas == 0):
        arr.append("Ideas I have for other projects\n")
        arr.append(input("What are those ideas?\n")+"\n")

    #writes the answers to the text file
    file = open("Thoughts.txt","w+")
    for x in arr:
        file.write(x)
    file.close()
    
    #makes the folder
    os.mkdir(programName)
    #Moves the dir
    shutil.move(folderPath+programName,"/Users/Eddie/Desktop/"+programName )
    #moves the file
    shutil.move(programPath+fileName,"/Users/Eddie/Desktop/"+programName+"/"+fileName)
    #moves the text file
    shutil.move(folderPath+"Thoughts.txt","/Users/Eddie/Desktop/"+programName+"/Thoughts.txt" )
else:
    print("There is no file named that ")