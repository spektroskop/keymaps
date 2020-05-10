.PHONY: all update unlink unlink_user

QMK_HOME := $(PWD)/qmk_firmware
USERNAME := spektroskop

all: compile

define make_keyboard
$(PWD)/qmk_firmware/keyboards/$(1)/keymaps/$(USERNAME):
	ln -s $(PWD)/$(1) $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/$(USERNAME)

.PHONY: compile--$(1)
compile--$(1): $(PWD)/qmk_firmware/users/$(USERNAME) $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/$(USERNAME)
	qmk compile -kb $(2) -km $(USERNAME)

.PHONY: flash--$(1)
flash--$(1): $(PWD)/qmk_firmware/users/$(USERNAME) $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/$(USERNAME)
	qmk flash -kb $(2) -km $(USERNAME)

.PHONY: unlink--$(1)
unlink--$(1):
	rm -f $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/$(USERNAME)

compile_targets += compile--$(1)
unlink_targets += unlink--$(1)
endef

init:
	git submodule init
	git submodule update

setup:
	qmk setup

update:
	git submodule foreach git pull origin master

$(eval $(call make_keyboard,planck,planck/ez))
$(eval $(call make_keyboard,preonic,preonic/rev3))

$(PWD)/qmk_firmware/users/$(USERNAME):
	ln -s $(PWD)/user $(PWD)/qmk_firmware/users/$(USERNAME)

unlink_user:
	rm -f $(PWD)/qmk_firmware/users/$(USERNAME)

compile: $(compile_targets)

unlink: unlink_user $(unlink_targets)