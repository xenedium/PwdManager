# PwdManager a cross-platform CLI password manager
USAGE: ./pwdmanager [--help] [--getpwd] [--setpwd] [--delpwd] [--listpwd] [args]

--getpwd [pwd] [name]: Get a stored password.

--setpwd [pwd] [name] [password]: Add or edit a password.

--delpwd [pwd] [name]: Delete a password.

--listpwd [pwd]: List all stored passwords.

# Infos
<h4>For Win32 users the password will be saved in APPDATA local folder inside %LOCALAPPDATA%\PwdManager\encdb.exdb</h4>
<h4>For Linux users the password will be saved in ~/.config/PwdManager/encdb.exdb</h4>