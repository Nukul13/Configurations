#!/usr/bin/python

"""Task list

1. arg parser cli interface
2. download retry with log
3. parallel download of videos of given number simultaneously
4. fetching video links from playlist page and creating a vidFile
"""

import sys
import os
import argparse   #Needs to be implemented

if sys.argv > 1:
    vidFile = open(sys.argv[1], 'r') 
    vidList = vidFile.readlines()
    f.close()
    for vid in vidList:
        # Some sort of download failure check
        # if fails retry 5 times
        # if continued to fails put in list and display at end
        os.system("youtube-dl -f 18 {0}".format(vid))   # Download 360 pix video

    