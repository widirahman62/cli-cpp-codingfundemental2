FROM alpine:latest
RUN apk update && apk add --no-cache inotify-tools && apk add --no-cache g++
WORKDIR /home/src
CMD ./autocompile.sh
