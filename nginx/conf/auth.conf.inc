# Login page to be sent to if auth result is 401.
# Pages with auth_request directive should also set
#  error_page 401 =200 /login;
location /login {
    proxy_pass http://goon-auth:4000/login;
    proxy_set_header X-Target $request_uri;
}

# Proxy authentication requests to GoonAuth, take second URI segment as group
# to be checked.
location ~^/auth_proxy/(?<group>.+)?$ {
    internal;
    rewrite (.*) "/auth" break;
    proxy_pass http://goon-auth:4000;
    proxy_pass_request_body off;
    proxy_set_header Content-length "";
    proxy_set_header X-Target "";
    proxy_set_header X-Access-Group $group;

    # Cache authentication results for 5 minutes
    proxy_ignore_headers Set-Cookie;
    proxy_cache auth_cache;
    proxy_cache_valid 200 403 5m;
    proxy_cache_key "$host$request_uri $cookie__goon_auth_key";
}
