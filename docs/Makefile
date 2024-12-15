INF_DOCNAME=informe
CUEST_DOCNAME=cuestiones
UM_DOCNAME=user_manual

all: informe cuestiones user_manual

.PHONY: clean

informe:
	pdflatex $(INF_DOCNAME).tex

cuestiones:
	pdflatex $(CUEST_DOCNAME).tex
	bibtex $(CUEST_DOCNAME).aux
	pdflatex $(CUEST_DOCNAME).tex
	pdflatex $(CUEST_DOCNAME).tex

user_manual:
	pdflatex $(UM_DOCNAME).tex

clean :
	rm -f *.bbl *.bcf *.blg *.synctex.gz *.toc *.aux *.log *.out
