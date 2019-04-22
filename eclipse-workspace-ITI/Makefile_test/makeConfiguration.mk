allSrcs = main.c
allSrcs+=MathGeek/MathGeek.c
allSrcs+=FastPrinter/FastPrinter.c
allSrcs+=ScanningEye/ScanningEye.c
allSrcs+=AngrySpeaker/AngrySpeaker.c
allSrcs+=TheOldWise/TheOldWise.c

fileHeader1 =
fileHeader2 = MathGeek.h
fileHeader3 = FastPrinter.h
fileHeader4 = ScanningEye.h 
fileHeader5 = AngrySpeaker.h
fileHeader6 = TheOldWise.h 

CC = gcc
VPATH = MathGeek:FastPrinter:ScanningEye:AngrySpeaker:TheOldWise
FinalTargetName=MasterApplication.exe
