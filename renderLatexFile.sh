#!/bin/bash
    
# make sure we have a tex file as first argument
if [ "$1" == "" ]; then
  echo "Usage: renderLatexFile.sh fileprefix"
  exit
else 
  if [ ! -e "$1.tex" ]; then
    echo "File $1.tex not found"
    exit
  fi
fi

echo "Generating $1.pdf"
printf "\n\n============ Generating $1.pdf =============\n\n" >> generator.log

fbase=$(basename -- "$1");
fname="${fbase%.*}"

# generate the pdf file
pdflatex --shell-escape -synctex=1 -interaction=nonstopmode "$1".tex >> generator.log
pdflatex --shell-escape -synctex=1 -interaction=nonstopmode "$1".tex >> generator.log

# clean up
rm -f "${fname}".aux "${fname}".fdb_latexmk "${fname}".fls "${fname}".log "${fname}".nav "${fname}".out "${fname}".snm "${fname}".synctex.gz "${fname}".toc

