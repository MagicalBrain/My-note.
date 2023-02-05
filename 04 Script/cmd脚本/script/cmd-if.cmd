echo "start checking:"
if exist %Doxygen% (    echo "Doxygen has been installed." && set doxygen=%Doxygen%)    else (    echo "Doxygen has not been installed yet.")
if exist %HYSDK_ROOT% ( echo "HYSDK_ROOT has been installed." && set HYSDK_ROOT=%HYSDK_ROOT%) else ( echo "HYSDK_ROOT has not been installed yet.")
