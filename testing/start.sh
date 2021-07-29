g++ src/strgen.cpp -o generate
g++ src/b64.cpp -o b64
cmake --build ../build/
cp ../build/pwdmanager ./
chmod +x ./pwdmanager
./generate
./b64
./pwdmanager
sha256sum enc_target.txt enc_output.txt dec_target.txt dec_output.txt
rm enc_output.txt dec_output.txt input.txt enc_target.txt dec_target.txt
