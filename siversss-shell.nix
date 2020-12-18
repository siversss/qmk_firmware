{}:
let orig = import ./shell.nix {arm=false;};
in

orig.overrideAttrs(oldAttrs: rec {
  shellHook = oldAttrs.shellHook + ''
    # Prevent the avr-gcc wrapper from picking up host GCC flags
    # like -iframework, which is problematic on Darwin
    unset NIX_CFLAGS_COMPILE_FOR_TARGET
  '';
})
