#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

SUCRECOIND=${SUCRECOIND:-$SRCDIR/sucrecoind}
SUCRECOINCLI=${SUCRECOINCLI:-$SRCDIR/sucrecoin-cli}
SUCRECOINTX=${SUCRECOINTX:-$SRCDIR/sucrecoin-tx}
SUCRECOINQT=${SUCRECOINQT:-$SRCDIR/qt/sucrecoin-qt}

[ ! -x $SUCRECOIND ] && echo "$SUCRECOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
XSRVER=($($SUCRECOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for sucrecoind if --version-string is not set,
# but has different outcomes for sucrecoin-qt and sucrecoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$SUCRECOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $SUCRECOIND $SUCRECOINCLI $SUCRECOINTX $SUCRECOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${XSRVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${XSRVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
