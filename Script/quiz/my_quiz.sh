#!/bin/bash

initialize(){
    trap 'summazrize; exit 0' INT
    num_ques=0
    num_correct=0
    first_time=true
    cd ${QUIZ_DIR:./exams} || exit 2
}