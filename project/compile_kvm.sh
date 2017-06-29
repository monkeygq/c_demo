#!/bin/bash
path="/usr/src/linux-4.4.60"
echo "==========================================>"
echo "[1] rmmod kvm_intel kvm start"
rmmod kvm-intel
if (($?));then
  echo "[INFO] rmmod kvm-intel failed"
else
  echo "[INFO] rmmod kvm-intel success"
fi
rmmod kvm 
if (($?));then
  echo "[INFO] rmmod kvm failed"
else
  echo "[INFO] rmmod kvm success"
fi
echo "[1] success!"
echo "==========================================>"
echo "[2] rm kvm-intel.ko kvm.ko"
rm /lib/modules/$(uname -r)/kernel/arch/x86/kvm/kvm.ko
if (($?));then
  echo "[INFO] rm kvm.ko failed"
else
  echo "[INFO] rm kvm.ko success"
fi
rm /lib/modules/$(uname -r)/kernel/arch/x86/kvm/kvm-intel.ko
if (($?));then
  echo "[INFO] rm kvm-intel.ko failed"
else
  echo "[INFO] rm kvm-intel.ko success"
fi
echo "[2] success!"
echo "==========================================>"
echo "[3] make clean kvm module"
make clean CONFIG_KVM=m CONFIG_INTEL_KVM=m -C ${path} M=${path}/arch/x86/kvm
if (($?));then
  echo "[ERROR] make clean kvm module failed"
  exit 1
else
  echo "[3] success!"
  echo "==========================================>"
fi
echo "[4] make kvm module"
make CONFIG_KVM=m CONFIG_INTEL_KVM=m -C ${path} M=${path}/arch/x86/kvm
if (($?));then
  echo "[ERROR] make kvm module failed"
  exit 1
else
  echo "[4] success!"
  echo "==========================================>"
fi
echo "[5] insmod kvm-intel.ko kvm.ko"
cp ${path}/arch/x86/kvm/kvm-intel.ko /lib/modules/$(uname -r)/kernel/arch/x86/kvm/
cp ${path}/arch/x86/kvm/kvm.ko /lib/modules/$(uname -r)/kernel/arch/x86/kvm/
echo "[5] success!"
echo "==========================================>"
echo "[6] modprobe kvm_intel kvm"
modprobe kvm_intel
modprobe kvm
lsmod|grep kvm
ls -l /dev/kvm
echo "[6] success!"
echo "==========================================>"
echo "[CONGRATULATIONS] recompile and insmod kvm success!"
