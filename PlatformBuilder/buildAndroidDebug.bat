rmdir /s /q %2
mkdir %2
unrar x ./AndroidPackage/MagnumAndroidLauncher.rar %2/"project/"
xcopy /E /Y /I /R /F "../device/application/bundle" %2"/project/MagnumAndroidLauncher/app/src/main/assets/device/application/bundle"