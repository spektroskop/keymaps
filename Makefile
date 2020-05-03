QMK_HOME := $(PWD)/qmk_firmware
USERNAME := spektroskop

define make_keyboard
$(PWD)/qmk_firmware/keyboards/$(1)/keymaps/$(USERNAME):
	ln -s $(PWD)/$(1) $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/$(USERNAME)

compile_$(1): $(PWD)/qmk_firmware/users/$(USERNAME) $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/$(USERNAME)
	qmk compile -kb $(2) -km $(USERNAME)

flash_$(1): $(PWD)/qmk_firmware/users/$(USERNAME) $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/$(USERNAME)
	qmk flash -kb $(2) -km $(USERNAME)
endef	

all: compile_planck compile_preonic

update: 
	git submodule foreach git pull origin master

$(PWD)/qmk_firmware/users/spektroskop:
	ln -s $(PWD)/user $(PWD)/qmk_firmware/users/$(USERNAME)

unlink:
	rm -f $(PWD)/qmk_firmware/users/$(USERNAME)
	rm -f $(PWD)/qmk_firmware/keyboards/planck/keymaps/$(USERNAME)
	rm -f $(PWD)/qmk_firmware/keyboards/preonic/keymaps/$(USERNAME)

$(eval $(call make_keyboard,planck,planck/ez))

$(eval $(call make_keyboard,preonic,preonic/rev3))

