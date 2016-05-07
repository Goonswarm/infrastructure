GoonSwarm DNS setup
===================

Our DNS zones are delegated to Google Cloud DNS.

Cloud DNS lets us transactionally import entire zones in the form of zone files,
this repository contains the zone files for our zones and a simple script to
update them.

Make some changes to a zone and run `./import ${zone_file_name}`. The `gcloud`
tool needs to be set up properly on your machine.
