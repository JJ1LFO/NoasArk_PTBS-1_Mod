# UML2SVG=./uml2svg.sh
UML2SVG= java -jar plantuml.jar -tsvg

SRCS=$(wildcard *.uml)
SVGS=$(SRCS:.uml=.svg)
EPSS=$(SVGS:.svg=.eps)

# all: $(SVGS) $(EPSS) 
all: $(SVGS)

clean:
	rm -f $(SVGS) $(EPSS)

%.svg: %.uml 
	$(UML2SVG) $<

%.eps: %.svg 
	rsvg-convert -f eps -o $(basename $<).eps  $<

