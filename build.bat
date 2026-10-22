@echo off
cls
echo Compilando arquivos de GreenLife...

if not exist dist mkdir dist

:: Para desativar todos os erros e avisos, apagar "-Wall" e "-Wextra" substitundo por -w, que silencia todos os alertas do compilador.

@g++ -std=c++17 -w -o dist/GreenLife.exe ^
src/*.cpp ^
src/classes_objects/sources/*.cpp ^
src/functions/sources/*.cpp

if %errorlevel% neq 0 (
    echo Erro na compilacao!
    pause
    exit /b
)

echo ________________________________________________
echo             Compilacao bem sucedida!            
echo             Executavel na pasta dist.
echo ________________________________________________
pause