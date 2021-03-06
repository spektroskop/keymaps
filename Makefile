.PHONY: all update unlink unlink_user

all: compile

QMK_HOME?=$(PWD)/qmk_firmware

define make-keyboard
$(QMK_HOME)/keyboards/$(1)/keymaps/spektroskop-$(3):
	ln -sf $(PWD)/keyboards/$(3) $(QMK_HOME)/keyboards/$(1)/keymaps/spektroskop-$(3)

compile-$(3): $(QMK_HOME)/users/spektroskop $(QMK_HOME)/keyboards/$(1)/keymaps/spektroskop-$(3)
	qmk compile -kb $(2) -km spektroskop-$(3)

flash-$(3): $(QMK_HOME)/users/spektroskop $(QMK_HOME)/keyboards/$(1)/keymaps/spektroskop-$(3)
	qmk flash -kb $(2) -km spektroskop-$(3) $(4)

unlink-$(3):
	rm -f $(QMK_HOME)/keyboards/$(1)/keymaps/spektroskop-$(3)

compile_targets += compile-$(3)
unlink_targets += unlink-$(3)
endef

init:
	git submodule init
	git submodule update

setup:
	qmk setup --yes -H $(QMK_HOME)

update:
	git submodule foreach git pull origin master
	git submodule foreach make git-submodule

$(QMK_HOME)/users/spektroskop:
	ln -s $(PWD)/user $(QMK_HOME)/users/spektroskop

unlink-user:
	rm -f $(QMK_HOME)/users/spektroskop

$(eval $(call make-keyboard,planck,planck/ez,planck,))
$(eval $(call make-keyboard,gboards/gergoplex,gboards/gergoplex,gergoplex,))
$(eval $(call make-keyboard,centromere,centromere,centromere,))
$(eval $(call make-keyboard,crkbd,crkbd,crkbd,-bl dfu))

compile: $(compile_targets)

unlink: unlink-user $(unlink_targets)
