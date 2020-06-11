#!/usr/bin/python3
"""
Write a script that reads stdin
line by line and computes metrics
"""

if __name__ == '__main__':

    import sys

    def printMetrix(fileSize, statusCodes):
        """
            prints the metrix
        """

        print("File size: {}".format(fileSize))
        for status, count in sorted(statusCodes.items()):
            if count:
                print("{}: {}".format(status, count))

    counter = 0
    fileSize = 0
    statusCodes = {"200": 0,
                   "301": 0,
                   "400": 0,
                   "401": 0,
                   "403": 0,
                   "404": 0,
                   "405": 0,
                   "500": 0
                   }
    try:
        for line in sys.stdin:
            counter += 1
            data = line.split()
            try:
                code = data[-2]
                if code in statusCodes:
                    statusCodes[code] += 1
                fileSize += int(data[-1])
            except BaseException:
                pass
            if counter % 10 == 0:
                printMetrix(fileSize, statusCodes)
        printMetrix(fileSize, statusCodes)
    except KeyboardInterrupt:
        printMetrix(fileSize, statusCodes)
        raise
