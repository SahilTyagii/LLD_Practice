@echo off
setlocal EnableDelayedExpansion

:: Set the output file name
set "output=combined_code.txt"

:: Delete the output file if it exists
if exist "%output%" (
    echo Deleting old %output%
    del "%output%"
)

:: Count files
set count=0

:: Search for both .cpp and .hpp files
for %%F in (*.cpp *.CPP *.hpp *.HPP) do (
    echo Processing: %%F
    echo ==== FILE: %%F ====>>"%output%"
    type "%%F">>"%output%"
    echo.>>"%output%"
    echo.>>"%output%"
    set /a count+=1
)

:: Report result
if %count%==0 (
    echo No .cpp or .hpp files found in %cd%
) else (
    echo Done. Combined content from %count% files saved to %output%.
)

pause
