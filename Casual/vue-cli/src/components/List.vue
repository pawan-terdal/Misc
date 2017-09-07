<template>
    <div>
        <server-item v-for="server in 5"></server-item>
    </div>
</template>

<script>
    import Item from './Item.vue';
    export default {

        components: {
            'server-item': Item
        }
    }
</script>

<style>

</style>
