if exist helpfile.cpp (exit)
echo #include ^<iostream^> >> helpfile.cpp
@echo. >> helpfile.cpp
echo using namespace std; >> helpfile.cpp
@echo. >> helpfile.cpp
echo int main(){ >> helpfile.cpp
@echo. >> helpfile.cpp
echo 	return 0; >> helpfile.cpp
echo } >> helpfile.cpp
start helpfile.cpp
exit
)