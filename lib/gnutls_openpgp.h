#ifndef GNUTLS_OPENPGP_H
#define GNUTLS_OPENPGP_H

int
gnutls_openpgp_set_key_file( GNUTLS_CERTIFICATE_CREDENTIALS res,
                             char *CERTFILE,
                             char* KEYFILE);
int gnutls_openpgp_extract_certificate_issuer_dn( const gnutls_datum *cert,
                                                  gnutls_dn *dn);
int gnutls_openpgp_extract_certificate_version( const gnutls_datum *cert );
time_t gnutls_openpgp_extract_certificate_activation_time(
                                                          const gnutls_datum
                                                          *cert );
time_t gnutls_openpgp_extract_certificate_expiration_time(
                                                          const gnutls_datum
                                                          *cert );
int gnutls_openpgp_verify_certificate( const gnutls_datum* cert_list,
                                       int cert_list_length);

int gnutls_openpgp_fingerprint( const gnutls_cert *cert, opaque *fpr,
                                size_t *fprlen );

int gnutls_openpgp_keyid( const gnutls_cert *cert, uint32 *keyid );


#endif /*GNUTLS_OPENPGP_H*/
