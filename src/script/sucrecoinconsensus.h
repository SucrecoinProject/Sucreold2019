// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Copyright (c) 2017 The Sucrecoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SUCRECOIN_SUCRECOINCONSENSUS_H
#define SUCRECOIN_SUCRECOINCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_SUCRECOIN_INTERNAL) && defined(HAVE_CONFIG_H)
#include "config/sucrecoin-config.h"
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBSUCRECOINCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define SUCRECOINCONSENSUS_API_VER 1

typedef enum sucrecoinconsensus_error_t
{
    sucrecoinconsensus_ERR_OK = 0,
    sucrecoinconsensus_ERR_TX_INDEX,
    sucrecoinconsensus_ERR_TX_SIZE_MISMATCH,
    sucrecoinconsensus_ERR_TX_DESERIALIZE,
    sucrecoinconsensus_ERR_AMOUNT_REQUIRED,
    sucrecoinconsensus_ERR_INVALID_FLAGS,
} sucrecoinconsensus_error;

/** Script verification flags */
enum
{
    sucrecoinconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    sucrecoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    sucrecoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    sucrecoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    sucrecoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    sucrecoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    sucrecoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    sucrecoinconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = sucrecoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH | sucrecoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               sucrecoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | sucrecoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               sucrecoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | sucrecoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int sucrecoinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, sucrecoinconsensus_error* err);

EXPORT_SYMBOL int sucrecoinconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, sucrecoinconsensus_error* err);

EXPORT_SYMBOL unsigned int sucrecoinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // SUCRECOIN_SUCRECOINCONSENSUS_H
