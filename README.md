# MMD asset importer for Godot

## What is it?

A Godot 4.0 module that imports MMD assets. It currently has
incomplete support for PMX models, but we intend to add at least VMD
motions as well.

## How do I use it?

We develop against Godot's `master` branch, so first check that out
with Git and make sure you can compile it. Then clone this repository
as `modules/pmx` under the Godot root and build again. At that point
you should be able to import PMX models inside your Godot project
folders. They will show up as packed scenes.

## How can I help?

Use it! Open issues for bugs and feature requests. Send us a PR. Chat
with us on V-Sekai's Discord server in `#animation`.

## Why Godot 4.0?

We only have so much free time, and Godot 3.x lacks support for custom
arrays, which makes support of dual quaternion skinning (QDEF) or
spherical blend skinning (SDEF) more difficult. We will consider
accepting PRs to add 3.x support if it looks like it will not be too
difficult to maintain or someone commits to maintaining it.
