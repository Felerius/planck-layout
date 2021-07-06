KEYMAP_DIR=qmk/keyboards/planck/keymaps/felerius

.PHONY: build
build:
	./qmk.sh compile -j4 -kb planck/rev4 -km felerius

.PHONY: flash
flash:
	./qmk.sh flash -j4 -kb planck/rev4 -km felerius

.PHONY: link
link: unlink
	ln -sf "$(realpath keymap)" "${KEYMAP_DIR}"

.PHONY: unlink
unlink:
	rm -rf  "${KEYMAP_DIR}"
