FROM gitlab.cs.wallawalla.edu:5050/cs_department/docker-images/pandoc_latex
COPY renderLatexFile.sh /app/renderLatexFile.sh
ENTRYPOINT ["/app/renderLatexFile.sh"]
WORKDIR /app/tex
