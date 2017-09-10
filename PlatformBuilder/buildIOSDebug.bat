rmdir /s /q %2
mkdir %2
unrar x ./IOSPackage/MagnumIOSLauncher.rar %2/"project/"
xcopy /E /Y /I /R /F "../device/application/bundle" %2"/project/MagnumIOSLauncher/EpicForceIOSLauncher/device/application/bundle"