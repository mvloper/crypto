FROM alpine

RUN apk add vim

RUN apk add gcc

RUN apk add libc-dev

COPY hello.c /
