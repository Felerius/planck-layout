#!/usr/bin/env bash

# Utility script running the qmk command using pipenv, with QMK_HOME set correctly

REPO_DIR="$(dirname "$(realpath "${BASH_SOURCE[0]}")")"

QMK_HOME="$REPO_DIR/qmk" pipenv run qmk "$@"
