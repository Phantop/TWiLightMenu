#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

ifeq ($(strip $(PROJECT)),)
export PROJECT	:=	$(CURDIR)/../
endif

export TARGET	:=	romsel_aktheme
NITRODATA		:=	nitrofiles

include $(DEVKITARM)/ds_rules

.PHONY: bootloader bootstub clean makearm7 makearm9 sound

all:	bootloader bootstub $(TARGET).nds

makearm7:
	$(MAKE) -C arm7
	cp arm7/$(TARGET).elf $(TARGET).arm7.elf

makearm9:
	$(MAKE) -C arm9
	cp arm9/$(TARGET).elf $(TARGET).arm9.elf

sound:
	@mkdir -p $(NITRODATA)/sound
	@cp ../romsel_dsimenutheme/nitrofiles/sound/defaultbg.wav $(NITRODATA)/sound/defaultbg.wav
	@cp ../romsel_dsimenutheme/nitrofiles/sound/defaultfx.bin $(NITRODATA)/sound/defaultfx.bin
	@cp ../romsel_dsimenutheme/nitrofiles/sound/saturnfx.bin $(NITRODATA)/sound/saturnfx.bin

dist:	all
	@mkdir -p ../7zfile/debug
	@cp $(TARGET).nds ../7zfile/_nds/TWiLightMenu/akmenu.srldr
	@cp $(TARGET).arm7.elf ../7zfile/debug/$(TARGET).arm7.elf
	@cp $(TARGET).arm9.elf ../7zfile/debug/$(TARGET).arm9.elf

$(TARGET).nds:	makearm7 makearm9 sound
	ndstool	-u 00030004 -g SRLA 01 "TWLMENUPP" -c $(TARGET).nds -7 $(TARGET).arm7.elf -9 $(TARGET).arm9.elf -d $(NITRODATA) \
  -b icon.bmp "Wood UI;TWiLight Menu++;Rocket Robz"

clean:
	@echo clean ...
	@rm -fr data
	@rm -fr $(NITRODATA)/sound
	@rm -fr $(BUILD) $(TARGET).elf $(TARGET).nds
	@rm -fr $(TARGET).arm7.elf
	@rm -fr $(TARGET).arm9.elf
	@$(MAKE) -C $(PROJECT)/universal/bootloader_menu clean
	@$(MAKE) -C $(PROJECT)/universal/bootstub clean
	@$(MAKE) -C arm9 clean
	@$(MAKE) -C arm7 clean

data:
	@mkdir -p data

bootloader: data
	@$(MAKE) -C $(PROJECT)/universal/bootloader_menu LOADBIN=$(CURDIR)/data/load.bin

bootstub: data
	@$(MAKE) -C $(PROJECT)/universal/bootstub BOOTSTUB=$(CURDIR)/data/bootstub.bin
