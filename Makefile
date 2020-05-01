QMK_HOME := $(PWD)/qmk_firmware

username := spektroskop
keymap = $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/$(username)_$(2)
qmk = qmk $(1) -kb $(2) -km $(username)_$(3)

all: compile_split_planck compile_preonic compile_split_preonic

$(PWD)/qmk_firmware/users/spektroskop:
	ln -s $(PWD)/user $(PWD)/qmk_firmware/users/$(username)

unlink:
	rm -f $(PWD)/qmk_firmware/users/$(username)
	rm -f $(PWD)/qmk_firmware/keyboards/planck/keymaps/$(username)*
	rm -f $(PWD)/qmk_firmware/keyboards/preonic/keymaps/$(username)*

$(call keymap,planck,split_planck):
	ln -s $(PWD)/split_planck $(call keymap,planck,split_planck)
compile_split_planck: $(call keymap,planck,split_planck)
	$(call qmk,compile,planck/ez,split_planck)
flash_split_planck: $(call keymap,planck,split_planck)
	$(call qmk,flash,planck/ez,split_planck)

$(call keymap,preonic,preonic):
	ln -s $(PWD)/preonic $(call keymap,preonic,preonic)
compile_preonic: $(call keymap,preonic,preonic)
	$(call qmk,compile,preonic/rev3,preonic)
flash_preonic: $(call keymap,preonic,preonic)
	$(call qmk,flash,preonic/rev3,preonic)

$(call keymap,preonic,split_preonic):
	ln -s $(PWD)/split_preonic $(call keymap,preonic,split_preonic)
compile_split_preonic: $(call keymap,preonic,split_preonic)
	$(call qmk,compile,preonic/rev3,split_preonic)
flash_split_preonic: $(call keymap,preonic,split_preonic)
	$(call qmk,flash,preonic/rev3,split_preonic)