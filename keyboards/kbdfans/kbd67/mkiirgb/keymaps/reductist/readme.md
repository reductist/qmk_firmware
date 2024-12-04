# KBDFANS KBD67 R2

Note this corresponds to the 'mkiirgb v3' keyboard for QMK.

This board uses a weird bootloader that mounts itself as a media drive, but attempting to write over FLASH.BIN with QMK-generated .bin firmware will disappear when the bootloader is unmounted.

My workaround was to rewrite the bytes in place:

```sh
dd if=/path/to/kbdfans_kbd67_mkiirgb_v3_reductist.bin of=/mount/path/KBDFANS/FLASH.BIN bs=512 conv=notrunc oflag=direct,sync
```

Note that this almost certainly will require root and my machines mount to `/run/media/pvr/KBDFANS/FLASH.BIN`
