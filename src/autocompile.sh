g++ -o main main.cpp;
./main;
while inotifywait -r /home/src/ -e create,modify,delete,move; do
rm ./main
g++ -o main main.cpp;
./main;
done
