#!/usr/bin/python

"""Task list

1. arg parser cli interface
2. download retry with log to file
3. parallel download of videos of given number simultaneously
4. fetching video links from playlist page and creating a vidFile
5. Autonumber the playlist sequence
"""

import sys
import os
import time
import argparse   #Needs to be implemented


start_time = time.time()

if sys.argv > 1:
    vidFile = open(sys.argv[1], 'r') 
    vidList = vidFile.readlines()
    vidFile.close()
    for count, vid in enumerate(vidList):
        # Some sort of download failure check
        # if fails retry 5 times
        # if continued to fails put in list and display at end
        error_msg = 0
        timeout = False
        failedVid = 0
        error_msg = os.system('youtube-dl -o "{0}-%(title)s.%(ext)s" -f 18 {1}'.format(count,vid))   # Download 360 pix video
        if error_msg != 0:
            for retry in range(4):
                print "retry "
                error_msg = os.system('youtube-dl -o "{0}-%(title)s.%(ext)s" -f 18 {1}'.format(count,vid))   # Download 360 pix video
                if error_msg == 0:
                    timeout == False
                    break
                elif retry == 3:
                    timeout = True
            if timeout == True:
                failedVid += 1
                print '\n\nFailed after {0} retries: {1}'.format(retry+2,vid)

print "\n\nTotal Failed videos: {0}".format(failedVid)
print("------------- %s seconds -------------" % (time.time() - start_time))

    