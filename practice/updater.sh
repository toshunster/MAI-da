#! /usr/bin/env bash

set -o errexit
set -o nounset
set -o pipefail

SOURCES_FILE=sources
LOG_FILE=log

function _log {
    local message=$2
    local type=$1
    echo "$(date +"%Y/%m/%d %H:%M:%S") [${type}] $message"
}

function log_error {
    local message=$1
    _log "ERR" "${message}"
}

function log_info {
    local message=$1
    _log "INFO" "${message}"
}

function site1parser {
    log_error "site1pareser"
}

function Main {
    exec >> ${LOG_FILE} 2>&1
    log_info "Start"
    for source in $( cat ${SOURCES_FILE} ); do
        echo ${source}
        if [ "${source}" == "site1" ]; then
            site1parser
        fi
    done
    log_info "End"
}

Main $@
