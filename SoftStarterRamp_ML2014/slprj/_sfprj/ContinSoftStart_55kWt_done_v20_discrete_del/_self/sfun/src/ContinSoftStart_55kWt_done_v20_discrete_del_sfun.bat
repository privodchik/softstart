@echo off
set COMPILER=cl 
				set COMPFLAGS=/c /GR /W3 /EHs /nologo /MD /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0  /DMATLAB_MEX_FILE -I"C:\Program Files\MATLAB\R2014a\extern\include" -I"C:\Program Files\MATLAB\R2014a\simulink\include" /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0  /DMATLAB_MEX_FILE  /DMATLAB_MEX_FILE 
				set OPTIMFLAGS=/O2 /Oy- /DNDEBUG 
				set DEBUGFLAGS=/Z7 
				set LINKER=link 
				set LINKFLAGS=/nologo  /manifest /export:%ENTRYPOINT% /DLL /LIBPATH:"C:\Program Files\MATLAB\R2014a\extern\lib\win64\microsoft" libmx.lib libmex.lib libmat.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib  ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /EXPORT:mexFunction 
				set LINKDEBUGFLAGS=/debug /PDB:"%OUTDIR%%MEX_NAME%.mexw64.pdb" 
				set NAME_OUTPUT=/out:"%OUTDIR%%MEX_NAME%%MEX_EXT%"
set PATH=$VSROOT\VC\Bin\amd64;$VSROOT\VC\Bin\VCPackages;$VSROOT\Common7\IDE;$VSROOT\Common7\Tools;$VSROOT\Common7\Tools\bin;$SDKROOT\Bin\x64;$SDKROOT\Bin\win64\x64;$SDKROOT\Bin;;%MATLAB_BIN%;%PATH%
set INCLUDE=$VSROOT\VC\ATLMFC\INCLUDE;$VSROOT\VC\INCLUDE;$SDKROOT\include;C:\Program Files\MATLAB\R2014a\extern\include;%INCLUDE%
set LIB=$VSROOT\VC\ATLMFC\LIB\amd64;$VSROOT\VC\Lib\amd64;$SDKROOT\Lib\X64;C:\Program Files\MATLAB\R2014a\lib\win64;C:\Program Files\MATLAB\R2014a\extern\lib\win64;;%LIB%
set LIBPATH=$VSROOT\VC\Lib\amd64;$VSROOT\VC\LIB\amd64;$VSROOT\VC\ATLMFC\LIB\amd64;$SDKROOT\lib\x64;C:\Program Files\MATLAB\R2014a\extern\lib\win64;;%LIBPATH%

nmake -f ContinSoftStart_55kWt_done_v20_discrete_del_sfun.mak
