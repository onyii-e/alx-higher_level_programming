#!/bin/bash

# Check if the user provided a URL argument
if [ $# -ne 1 ]; then
    echo "Usage: $0 <URL>"
    exit 1
fi

# Send request to the provided URL and measure the body size
curl -sI "$1" | grep -i Content-Length | awk '{print $2}'
