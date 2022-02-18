mv docs/Doxyfile Doxyfile
mv docs/doxygen-awesome.css doxygen-awesome.css
R -e "Sys.setenv(RSTUDIO_PANDOC='/usr/lib/rstudio/bin/pandoc'); pkgdown::clean_site(); pkgdown::build_site()"
mv Doxyfile docs/Doxyfile 
mv doxygen-awesome.css docs/doxygen-awesome.css 
doxygen docs/Doxyfile
