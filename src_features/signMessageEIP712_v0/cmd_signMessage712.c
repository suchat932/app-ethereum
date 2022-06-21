#include "shared_context.h"
#include "apdu_constants.h"
#include "utils.h"
#include "ui_flow.h"
#include "eip712.h"
#include "common_712.h"

void handleSignEIP712Message_v0(uint8_t p1,
                                uint8_t p2,
                                uint8_t *workBuffer,
                                uint8_t dataLength,
                                unsigned int *flags,
                                unsigned int *tx) {
    UNUSED(tx);
    if ((p1 != 00) || (p2 != 00)) {
        THROW(0x6B00);
    }
    if (appState != APP_STATE_IDLE) {
        reset_app_context();
    }

    if (!handle_sign_712_common_apdu_parse(&workBuffer, &dataLength))
    {
        THROW(0x6a80);
    }

    if (dataLength < (KECCAK256_HASH_BYTESIZE * 2)) {
        PRINTF("Invalid data\n");
        THROW(0x6a80);
    }
    memmove(tmpCtx.messageSigningContext712.domainHash,
            workBuffer,
            KECCAK256_HASH_BYTESIZE);
    memmove(tmpCtx.messageSigningContext712.messageHash,
            workBuffer + KECCAK256_HASH_BYTESIZE,
            KECCAK256_HASH_BYTESIZE);

#ifdef NO_CONSENT
    io_seproxyhal_touch_signMessage_ok(NULL);
#else   // NO_CONSENT
    ux_flow_init(0, ux_sign_712_v0_flow, NULL);
#endif  // NO_CONSENT

    *flags |= IO_ASYNCH_REPLY;
}
