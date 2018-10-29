#!/bin/bash

dir(){
    if [[ ${#1} -eq 0  ||  -d "$1" ]];then
	return 0
    fi
    if [[ "${1%/*}" = "$1" ]];then
	mkdir $1
	return $?
    fi
    dir ${1%/*} || return 1
    mkdir $1
}

set -o xtrace

dir $1