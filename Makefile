.PHONY: all update unlink unlink_user

QMK_HOME := $(PWD)/qmk_firmware

all: compile

define make_keyboard
$(PWD)/qmk_firmware/keyboards/$(1)/keymaps/spektroskop:
	ln -s $(PWD)/$(1) $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/spektroskop

.PHONY: compile--$(1)
compile--$(1): $(PWD)/qmk_firmware/users/spektroskop $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/spektroskop
	qmk compile -kb $(2) -km spektroskop

.PHONY: flash--$(1)
flash--$(1): $(PWD)/qmk_firmware/users/spektroskop $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/spektroskop
	qmk flash -kb $(2) -km spektroskop

.PHONY: unlink--$(1)
unlink--$(1):
	rm -f $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/spektroskop

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
	git submodule foreach make git-submodule

$(eval $(call make_keyboard,planck,planck/ez))

$(PWD)/qmk_firmware/users/spektroskop:
	ln -s $(PWD)/user $(PWD)/qmk_firmware/users/spektroskop

unlink_user:
	rm -f $(PWD)/qmk_firmware/users/spektroskop

compile: $(compile_targets)

unlink: unlink_user $(unlink_targets)
