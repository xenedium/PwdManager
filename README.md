# PwdManager a cross-platform CLI password manager
USAGE: ./pwdmanager [--help] [--getpwd] [--setpwd] [--delpwd] [--listpwd] [args]

--getpwd [pwd] [name]: Get a stored password.

--setpwd [pwd] [name] [password]: Add or edit a password.

--delpwd [pwd] [name]: Delete a password.

--listpwd [pwd]: List all stored passwords.

# Infos
<h4>For Win32 users the passwords will be saved in APPDATA local folder inside %LOCALAPPDATA%\PwdManager\encdb.exdb</h4>
<h4>For Linux users the passwords will be saved in ~/.config/PwdManager/encdb.exdb</h4>

The passwords are encrypted using AES-256 and the mainapp password is hashed with sha512.

# .exdb file format
The .exdb file is a binary file with the following structure (little endian):
the first 4 bytes are the file version.
the next 64 bytes are the password hash.
the next 4 bytes are the number of passwords.

after that, each password is saved in the following format:
the first 10 bytes are the password name.



# TODO:
fix little/big endian issue with sha512
implement aes256
