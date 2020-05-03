.PHONY: all update unlink unlink_user

QMK_HOME := $(PWD)/qmk_firmware
USERNAME := spektroskop

all: compile_planck compile_preonic

update:
	git submodule foreach git pull origin master

define make_keyboard
$(PWD)/qmk_firmware/keyboards/$(1)/keymaps/$(USERNAME):
	ln -s $(PWD)/$(1) $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/$(USERNAME)

.PHONY: compile_$(1)
compile_$(1): $(PWD)/qmk_firmware/users/$(USERNAME) $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/$(USERNAME)
	qmk compile -kb $(2) -km $(USERNAME)

.PHONY: flash_$(1)
flash_$(1): $(PWD)/qmk_firmware/users/$(USERNAME) $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/$(USERNAME)
	qmk flash -kb $(2) -km $(USERNAME)

.PHONY: unlink_$(1)
unlink_$(1):
	rm -f $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/$(USERNAME)

unlink_keyboards += unlink_$(1)
endef	

$(PWD)/qmk_firmware/users/$(USERNAME):
	ln -s $(PWD)/user $(PWD)/qmk_firmware/users/$(USERNAME)

unlink_$(USERNAME):
	rm -f $(PWD)/qmk_firmware/users/$(USERNAME)

$(eval $(call make_keyboard,planck,planck/ez))

$(eval $(call make_keyboard,preonic,preonic/rev3))

unlink: unlink_$(USERNAME) $(unlink_keyboards)
