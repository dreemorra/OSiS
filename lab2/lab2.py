import os

path = "/home/mora/Downloads"

if __name__ == "__main__":
    fileSizeList = []
    largestSize = 0

    for root, dirs, files in os.walk(path):
        for file in files:
            fileSizeList.append((file, os.path.getsize(os.path.join(root, file))))
    try:
        for fileName, fileSize in fileSizeList:
            if fileSize > largestSize:
                largestSize = fileSize
                largestFile = fileName
        print("\nLargest file: {}, {} bytes".format(fileName, fileSize))
        
    except:
        print("Wrong path!")