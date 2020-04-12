#pandoc3
import os
import re

# Find all the markdown files.
def findAllmarkdown():
    mdlist = []
    pandoclist = []
    for root, dirs, files in os.walk("."):
        for f in files:
            fullpath = os.path.join(root,f)
            if fullpath.endswith(".md"):
                mdlist.append((fullpath, root, f))
    return mdlist

mdlist = findAllmarkdown()

# Copy the files. import shutil

def createPandocFile(fullpath, root, f):
    # keep it simple
    temp2 =  f+'.pandoc'
    pandocfilename = root +'/'+ temp2
    shutil.copyfile(fullpath,pandocfilename)
    return pandocfilename

pdlist = []

for file in mdlist:
    filepathfilename = file[0]
    rootpath = file[1]
    filename = file[2]
    temp = createPandocFile(filepathfilename, rootpath, filename)
    pdlist.append((temp, rootpath))


# success -- now just need to loop through all the files.
pattern = "!\[(.*?)\]\((.*?)\)"
pattern2 = "!\[(.*?)\]"

def prependPath(line, path):
    linesplit = line.split('(')
    description = linesplit[0]
    relpath = linesplit[1]

    # is this image local or not

    #relpathstruct = relpath.split('/')

    # always add the path relative to this one before
    newline = ("".join(['(',path,'/',relpath]))
    return newline

import fileinput
import sys

for pd in pdlist:
    print(pd)
    filepathfilename = pd[0]
    rootpath = pd[1]


    for line in fileinput.input(filepathfilename,inplace=True):
        test= re.match(pattern, line)
        #print(test)
        if test != None:
            # get the description
            start = re.match(pattern2,line)
            # adjust the path

            derp = prependPath(line,rootpath)
            replaceline = start.group()+ derp
            #print(line)
            #print(replaceline)
            line = line.replace(line, replaceline)
        #print(line) -- adds newlines everywhere
        sys.stdout.write(line)

    fileinput.close()
            
