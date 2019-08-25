#!/bin/bash

flatpak-builder ./flatpak-build com.github.xournalpp.xournalpp.yaml --force-clean --repo=./repo --jobs=1
flatpak build-bundle ./repo  xournalpp.flatpak com.github.xournalpp.xournalpp
