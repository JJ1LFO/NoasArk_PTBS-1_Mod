# UML2SVG=./uml2svg.sh
UML2SVG= java -jar plantuml.jar -tsvg
SVG2PNG= convert

SRCS=$(wildcard *.uml)
SVGS=$(SRCS:.uml=.svg)
EPSS=$(SVGS:.svg=.eps)
PNGS=$(SVGS:.svg=.png)


# all: $(SVGS) $(EPSS) 
all: $(SVGS) $(PNGS)

clean:
	rm -f $(SVGS) $(EPSS)

%.svg: %.uml 
	$(UML2SVG) $<

%.eps: %.svg 
	rsvg-convert -f eps -o $(basename $<).eps  $<

%.png: %.svg 
	$(SVG2PNG) $< $@
